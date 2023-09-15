using Trie = trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update>;

bool string_existe (Trie& T, string& s) {
   auto [from, to] = T.prefix_range(x);
   return from != to && *from == x;
}

void print_prefix_matches (Trie& T, string& prefix) {
  auto [from, to] = T.prefix_range(prefix);
  for (auto it = from; it != to; it++) cout << *it << ' ';
  cout << endl;
}