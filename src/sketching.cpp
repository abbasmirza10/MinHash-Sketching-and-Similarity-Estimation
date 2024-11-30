#include "sketching.h"

//PART 1

// std::vector<uint64_t> kminhash(std::vector<int> inList, unsigned k, hashFunction h) {
//     //TODO - CANNOT use std::sort - exceeds 6second PL timeout
//     std::vector<uint64_t> mins(k, GLOBAL_MAX_INT);
//     for (const auto& item : inList) {
//         uint64_t hashedValue = h(item);
//         auto it = std::find(mins.begin(), mins.end(), hashedValue);
//         if (it != mins.end()) {
//             continue; // Skip duplicates
//         }
//         it = std::max_element(mins.begin(), mins.end());
//         if (hashedValue < *it) {
//             *it = hashedValue;
//         }
//     }
//     std::sort(mins.begin(), mins.end());
//     return mins;
// }


std::vector<uint64_t> kminhash(std::vector<int> inList, unsigned k, hashFunction h) {
    std::vector<uint64_t> minHashes(k, GLOBAL_MAX_INT);
    std::unordered_set<uint64_t> hashSet;
    for (int number : inList) {
        uint64_t hashValue = h(number);
        if (hashSet.insert(hashValue).second) {
            // Update the k minimum values
            for (unsigned i = 0; i < k; ++i) {
                if (hashValue < minHashes[i]) {
                    minHashes.insert(minHashes.begin() + i, hashValue);
                    minHashes.pop_back();
                    break;
                }
            }
        }
    }
    return minHashes;
}

std::vector<uint64_t> khash_minhash(std::vector<int> inList, std::vector<hashFunction> hv) {
    //TODO
    std::vector<uint64_t> checkMinHashVals(hv.size(), GLOBAL_MAX_INT);
    for (int value : inList) {
        for (size_t i = 0; i < hv.size(); ++i) {
            uint64_t hashValue = hv[i](value);
            if (hashValue < checkMinHashVals[i]) {
                checkMinHashVals[i] = hashValue;
            }
        }
    }
    return checkMinHashVals;
}



std::vector<uint64_t> kpartition_minhash(std::vector<int> inList, int part_bits, hashFunction h) {
    //TODO - C
    std::vector<uint64_t> minHashes(1ULL << part_bits, GLOBAL_MAX_INT);
    for (int value : inList) {
        uint64_t hashValue = h(value);
        int partition = hashValue >> (64 - part_bits);
        if (hashValue < minHashes[partition]) {
            minHashes[partition] = hashValue;
        }
    }
    return minHashes;
}


// float minhash_jaccard(std::vector<uint64_t> mh1, std::vector<uint64_t> mh2) {
//     //TODO - unordered_set --> CHANGE
//     std::sort(mh1.begin(), mh1.end());
//     std::sort(mh2.begin(), mh2.end());
//     float elements = 0.0;
//     float mid = 0.0;
//     auto it1 = mh1.begin();
//     auto it2 = mh2.begin();
//     while (it1 != mh1.end() && it2 != mh2.end()) {
//         if (*it1 == *it2 && *it1 != GLOBAL_MAX_INT) {
//             mid++;
//             elements++;
//             it1++;
//             it2++;
//         } else if (*it1 < *it2) {
//             elements++;
//             it1++;
//         } else {
//             elements++;
//             it2++;
//         }
//     }
//     elements += std::distance(it1, mh1.end());
//     elements += std::distance(it2, mh2.end());
//     if (elements == 0.0) {
//         return 0.0;
//     }
//     float toReturn = mid / elements;
//     return toReturn;
// }


float minhash_jaccard(const std::vector<uint64_t> mh1, const std::vector<uint64_t> mh2) {
    // Create lambda function for removing GLOBAL_MAX_INT
    auto remove_global_max = [](const auto& vec) {
        std::vector<uint64_t> result;
        std::copy_if(vec.begin(), vec.end(), std::back_inserter(result),
                     [](uint64_t value) { return value != GLOBAL_MAX_INT; });
        return result;
    };
    auto mh1_copy = remove_global_max(mh1);
    auto mh2_copy = remove_global_max(mh2);
    auto set1 = std::unordered_set<uint64_t>(mh1_copy.begin(), mh1_copy.end());
    auto set2 = std::unordered_set<uint64_t>(mh2_copy.begin(), mh2_copy.end());
    std::unordered_set<uint64_t> uni(set1.begin(), set1.end());
    uni.insert(set2.begin(), set2.end());
    std::unordered_set<uint64_t> inter;
    for (const auto& element : set1) {
        if (set2.find(element) != set2.end()) {
            inter.insert(element);
        }
    }
    if (uni.empty()) return 0.0f; // Avoid division by zero
    return static_cast<float>(inter.size()) / static_cast<float>(uni.size());
}



int minhash_cardinality(std::vector<uint64_t> mh, unsigned k) {
    //TODO
    float maxInt = static_cast<float>(GLOBAL_MAX_INT);
    float lastElement = static_cast<float>(mh[k - 1]);
    int cardVal = static_cast<int>(k / (lastElement / maxInt));
    return cardVal;
}

float exact_jaccard(std::vector<int> raw1, std::vector<int> raw2) {
    //TODO
    std::set<int> set1(raw1.begin(), raw1.end());
    std::set<int> set2(raw2.begin(), raw2.end());
    size_t intersectCount = 0;
    size_t unionCount = set1.size() + set2.size();
    for (int value : set1) {
        if (set2.count(value) > 0) {
            ++intersectCount;
            --unionCount;
        }
    }
    if (unionCount == 0) {
        return 0.0f;  // To avoid division by zero
    }

    return static_cast<float>(intersectCount) / static_cast<float>(unionCount);
}

int exact_cardinality(std::vector<int> raw) {
    //TODO
    std::set<int> uniqueSet(raw.begin(), raw.end());
    return static_cast<int>(uniqueSet.size());
}

//PART 2


MM::MM(const cs225::PNG& input, unsigned numTiles, unsigned k, hashFunction h) {
    int width = input.width();
    int height = input.height();
    int width_length = std::ceil(static_cast<double>(width) / numTiles);
    int height_length = std::ceil(static_cast<double>(height) / numTiles);
    for (unsigned row = 0; row < numTiles; row++) {
        std::vector<std::vector<uint64_t>> rowVector;
        for (unsigned col = 0; col < numTiles; col++) {
            //firstX = x coordinate(horizontal) of the top left corner of the curr tile
            //firstY = y coordinate(vertical) of the top left corner of the curr tile
            //lastX, lastY = x, y coordinate just beyond the right/bottom edge of the curr tile - ensures everything within range seen
            int firstX = col * width_length;
            int firstY = row * height_length;
            int lastX = std::min(firstX + width_length , width);
            int lastY = std::min(firstY + height_length, height);
            std::vector<int> tilePix;
            for (int y = firstY; y < lastY; y++) {
                for (int x = firstX; x < lastX; x++) {
                    auto pix = input.getPixel(x, y);
                    tilePix.push_back(pix.l * 255);
                }
            }
            std::vector<uint64_t> calculatedMinHash = kminhash(tilePix, k, h);
            rowVector.push_back(calculatedMinHash);
        }
        minHashMatrix.push_back(rowVector);
    }
}


std::vector<uint64_t> MM::getMinHash(unsigned width, unsigned height) const {
    return minHashMatrix[height][width]; 
}



int MM::countMatchTiles(const MM& other, float threshold) const {
    int matchCount = 0;
    //minHashMatrix.size() - rows
    //minHashMatrix[row].size - cols
    for (unsigned row = 0; row < minHashMatrix.size(); row++) {
        for (unsigned col = 0; col < minHashMatrix[row].size(); col++) {
            std::vector<uint64_t> minHash1 = minHashMatrix[row][col];
            std::vector<uint64_t> minHash2 = other.minHashMatrix[row][col];
            float jaccardSimilarity = minhash_jaccard(minHash1, minHash2);

            if (jaccardSimilarity >= threshold) {
                matchCount++;
            }
        }
    }
    return matchCount;
}



// PART 3

std::vector<std::tuple<int, int, int>> build_minhash_graph(std::vector<std::string> flist, unsigned numTiles, unsigned k, hashFunction h, float threshold) {
    //TODO - temporarily returning val to compile test suite
    std::vector<std::tuple<int, int, int>> toReturn;
    std::vector<MM> minHashMatrices;
    for (const auto& file : flist) {
        cs225::PNG image;
        image.readFromFile(file);
        MM mm(image, numTiles, k, h);
        minHashMatrices.push_back(mm);
    }
    for (size_t i = 0; i < flist.size(); ++i) {
        for (size_t j = i + 1; j < flist.size(); ++j) {
            int matchCount = minHashMatrices[i].countMatchTiles(minHashMatrices[j], threshold);
            if (matchCount > 0) {
                toReturn.push_back(std::make_tuple(static_cast<int>(i), static_cast<int>(j), matchCount));
            }
        }
    }
    return toReturn;
}

