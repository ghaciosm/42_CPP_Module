#include "PmergeMe.hpp"

void	merge_vec(std::vector<int>& my_vec, int front, int mid, int back)
{
    int i = 0;
	int j = 0;
	int k = 0;
	
    int n1 = mid - front + 1;
    int n2 = back - mid;

    std::vector<int> L(n1), R(n2);

    while(i < n1)
	{
        L[i] = my_vec[front + i];
		i++;
	}
	while (j < n2)
	{
        R[j] = my_vec[mid + 1 + j];
		j++;
	}

    i = 0;
    j = 0;
    k = front;
    while (i < n1 && j < n2)
	{
        if (L[i] <= R[j])
            my_vec[k] = L[i++];
        else
            my_vec[k] = R[j++];
        k++;
    }

    while (i < n1)
        my_vec[k++] = L[i++];

    while (j < n2)
        my_vec[k++] = R[j++];
}
void	merge_deq(std::deque<int> &deq, int front, int mid, int back)
{
    int i = 0;
	int j = 0;
	int k = 0;
	
    int n1 = mid - front + 1;
    int n2 = back - mid;

    std::deque<int> L(n1), R(n2);

    while(i < n1)
	{
        L[i] = deq[front + i];
		i++;
	}
	while (j < n2)
	{
        R[j] = deq[mid + 1 + j];
		j++;
	}

    i = 0;
    j = 0;
    k = front;
    while (i < n1 && j < n2)
	{
        if (L[i] <= R[j])
            deq[k] = L[i++];
        else
            deq[k] = R[j++];
        k++;
    }

    while (i < n1)
        deq[k++] = L[i++];

    while (j < n2)
        deq[k++] = R[j++];
}

void	merge_insert_sort_vec(std::vector<int>& my_vec, int front, int back)
{
    if (front < back)
	{
        int mid = front + (back - front) / 2;

        merge_insert_sort_vec(my_vec, front, mid);
        merge_insert_sort_vec(my_vec, mid + 1, back);

        merge_vec(my_vec, front, mid, back);
    }
}
void	merge_insert_sort_deq(std::deque<int> &deq, int front, int back)
{
    if (front < back)
	{
        int mid = front + (back - front) / 2;

        merge_insert_sort_deq(deq, front, mid);
        merge_insert_sort_deq(deq, mid + 1, back);

        merge_deq(deq, front, mid, back);
    }
}