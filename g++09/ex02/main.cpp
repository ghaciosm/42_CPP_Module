#include "PmergeMe.hpp"
#include <ctime>

void print_vec(const std::vector<int>& container) 
{
    size_t i = 0;
    while (i < container.size()) 
    {
        std::cout << container[i] << " ";
        i++;
    }
    std::cout << std::endl;
}

void	print_deq(std::deque<int> & deq)
{
	std::deque<int>::iterator	it = deq.begin();
	while (it != deq.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error\n";
		return (1);
	}
    std::vector<int>	vect;
    std::deque<int>		deq;

    int i = 1;
	while (i < ac) 
    {
        std::istringstream iss(av[i]);
        int value;
        if (!(iss >> value) || value <= 0 ) 
        {
            std::cerr << "Error: Invalid or negative input format." << std::endl;
            return 1;
        }
        vect.push_back(value);
        deq.push_back(value);
        i++;
    }

	std::cout << "Before:\t";
	print_vec(vect);

	clock_t	start_t = clock();
	merge_insert_sort_vec(vect, 0, vect.size() - 1);
	clock_t	end_t = clock();

	std::cout << "After:\t";
	print_vec(vect);

	std::cout << "Time to process a range of";
	std::cout << std::setw(5) << vect.size();
	std::cout << " elements with std::vector : " << std::fixed << (double)(end_t - start_t) / CLOCKS_PER_SEC  << " s" << std::endl;

	start_t = clock();
	merge_insert_sort_deq(deq, 0, deq.size() - 1);
	end_t = clock();
	//print_deq(deq);

	std::cout << "Time to process a range of";
	std::cout << std::setw(5) << deq.size();
	std::cout << " elements with std::deque  : " << std::fixed << (double)(end_t - start_t) / CLOCKS_PER_SEC  << " s" << std::endl;

	return (0);
}