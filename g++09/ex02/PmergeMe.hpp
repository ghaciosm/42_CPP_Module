#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <vector>
# include <deque>
# include <sstream>

void	fill_containers(std::vector<int> &vect,std::deque<int> &deq,std::string str);
void	merge_vec(std::vector<int>& my_vec, int front, int mid, int back);
void	merge_deq(std::deque<int> &deq, int front, int mid, int back);
void	merge_insert_sort_vec(std::vector<int>& my_vec, int front, int back);
void	merge_insert_sort_deq(std::deque<int> &deq, int front, int back);

#endif
