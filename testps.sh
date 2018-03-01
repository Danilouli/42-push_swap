while true; do
  ./push_swap `ruby -e "puts (0..500).to_a.shuffle.join(' ')"` | wc -l
done
