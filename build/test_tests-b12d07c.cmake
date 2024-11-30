add_test( test_kminhash /workspaces/cs225git/mp_sketching/build/test test_kminhash  )
set_tests_properties( test_kminhash PROPERTIES WORKING_DIRECTORY /workspaces/cs225git/mp_sketching/build)
add_test( test_khash /workspaces/cs225git/mp_sketching/build/test test_khash  )
set_tests_properties( test_khash PROPERTIES WORKING_DIRECTORY /workspaces/cs225git/mp_sketching/build)
add_test( test_kpartition /workspaces/cs225git/mp_sketching/build/test test_kpartition  )
set_tests_properties( test_kpartition PROPERTIES WORKING_DIRECTORY /workspaces/cs225git/mp_sketching/build)
add_test( test_exact_cardinality /workspaces/cs225git/mp_sketching/build/test test_exact_cardinality  )
set_tests_properties( test_exact_cardinality PROPERTIES WORKING_DIRECTORY /workspaces/cs225git/mp_sketching/build)
add_test( test_minhash_cardinality /workspaces/cs225git/mp_sketching/build/test test_minhash_cardinality  )
set_tests_properties( test_minhash_cardinality PROPERTIES WORKING_DIRECTORY /workspaces/cs225git/mp_sketching/build)
add_test( test_exact_jaccard /workspaces/cs225git/mp_sketching/build/test test_exact_jaccard  )
set_tests_properties( test_exact_jaccard PROPERTIES WORKING_DIRECTORY /workspaces/cs225git/mp_sketching/build)
add_test( test_minhash_jaccard /workspaces/cs225git/mp_sketching/build/test test_minhash_jaccard  )
set_tests_properties( test_minhash_jaccard PROPERTIES WORKING_DIRECTORY /workspaces/cs225git/mp_sketching/build)
add_test( [==[test_png_minhash (uniform minhash)]==] /workspaces/cs225git/mp_sketching/build/test [==[test_png_minhash (uniform minhash)]==]  )
set_tests_properties( [==[test_png_minhash (uniform minhash)]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225git/mp_sketching/build)
add_test( [==[test_png_minhash (black-white simple tests)]==] /workspaces/cs225git/mp_sketching/build/test [==[test_png_minhash (black-white simple tests)]==]  )
set_tests_properties( [==[test_png_minhash (black-white simple tests)]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225git/mp_sketching/build)
add_test( [==[test_png_minhash (total random hash1 mixed sizes)]==] /workspaces/cs225git/mp_sketching/build/test [==[test_png_minhash (total random hash1 mixed sizes)]==]  )
set_tests_properties( [==[test_png_minhash (total random hash1 mixed sizes)]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225git/mp_sketching/build)
add_test( [==[test_png_minhash (total random rectangular PNGs)]==] /workspaces/cs225git/mp_sketching/build/test [==[test_png_minhash (total random rectangular PNGs)]==]  )
set_tests_properties( [==[test_png_minhash (total random rectangular PNGs)]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225git/mp_sketching/build)
add_test( [==[test_png_matchingTiles (sixcolor_100_100)]==] /workspaces/cs225git/mp_sketching/build/test [==[test_png_matchingTiles (sixcolor_100_100)]==]  )
set_tests_properties( [==[test_png_matchingTiles (sixcolor_100_100)]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225git/mp_sketching/build)
add_test( [==[test_png_matchingTiles (r_500_500)]==] /workspaces/cs225git/mp_sketching/build/test [==[test_png_matchingTiles (r_500_500)]==]  )
set_tests_properties( [==[test_png_matchingTiles (r_500_500)]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225git/mp_sketching/build)
add_test( [==[test_build_minhash_graph (sixcolor_100_100)]==] /workspaces/cs225git/mp_sketching/build/test [==[test_build_minhash_graph (sixcolor_100_100)]==]  )
set_tests_properties( [==[test_build_minhash_graph (sixcolor_100_100)]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225git/mp_sketching/build)
add_test( [==[test_build_minhash_graph (r_500_500)]==] /workspaces/cs225git/mp_sketching/build/test [==[test_build_minhash_graph (r_500_500)]==]  )
set_tests_properties( [==[test_build_minhash_graph (r_500_500)]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225git/mp_sketching/build)
add_test( [==[My Test Case]==] /workspaces/cs225git/mp_sketching/build/test [==[My Test Case]==]  )
set_tests_properties( [==[My Test Case]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225git/mp_sketching/build)
set( test_TESTS test_kminhash test_khash test_kpartition test_exact_cardinality test_minhash_cardinality test_exact_jaccard test_minhash_jaccard [==[test_png_minhash (uniform minhash)]==] [==[test_png_minhash (black-white simple tests)]==] [==[test_png_minhash (total random hash1 mixed sizes)]==] [==[test_png_minhash (total random rectangular PNGs)]==] [==[test_png_matchingTiles (sixcolor_100_100)]==] [==[test_png_matchingTiles (r_500_500)]==] [==[test_build_minhash_graph (sixcolor_100_100)]==] [==[test_build_minhash_graph (r_500_500)]==] [==[My Test Case]==])
