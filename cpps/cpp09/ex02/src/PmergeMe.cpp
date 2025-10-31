#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **input)
{
	std::string args_string;
    std::deque<int> input_deque;
    std::vector<int> input_vector;
    for (int i = 1; input[i];i++)
	{
        args_string += input[i];
        if(input[i] != NULL)
            args_string += " ";   
    }
    std::istringstream ss(args_string);
    int n;
    while(ss >> n)
	{
        if (std::find(input_deque.begin(), input_deque.end(), n) != input_deque.end())
            throw std::runtime_error("Duplicate value detected");
        input_deque.push_back(n);
        input_vector.push_back(n);
    }
    // if(container.size() != count_word_and_check(args_string))
    //     throw std::runtime_error("Unexpected error");
    _deq = input_deque;
    _vec = input_vector;
}

PmergeMe::~PmergeMe()
{
}


PmergeMe::PmergeMe(const PmergeMe &other)
{
    _vec = other._vec;
    _deq = other._deq;
}

std::deque<int>& PmergeMe::getDeque()
{
    return _deq;
}

std::vector<int>& PmergeMe::getVector()
{
    return _vec;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _deq = other._deq;
        _vec = other._vec;
    }
    return *this;
}

std::deque<size_t> jacobsthal_sequence(size_t n)
{
    std::deque<size_t> seq;
    seq.push_back(0);
    seq.push_back(1);
    while (seq.back() < n)
        seq.push_back(seq[seq.size() - 1] + 2 * seq[seq.size() - 2]);
    return seq;
}

void PmergeMe::mergeInsertionDeque(std::deque<int> &deque)
{
    if (deque.size() <= 1)
        return;

    std::deque<int> small;
    std::deque<int> big;

    for (size_t i = 0; i < deque.size() - 1; i+=2)
    {
        int a = deque[i];
        int b = deque[i + 1];

        if (a > b)
        {
            big.push_back(a);
            small.push_back(b);
        }
        else
        {
            big.push_back(b);
            small.push_back(a);
        }
    }

    if (deque.size() % 2 != 0)
        big.push_back(deque.back());

    mergeInsertionDeque(big);

    std::deque<size_t> jacob = jacobsthal_sequence(small.size());
    std::deque<size_t> order;
    size_t prev = 0;

    for (size_t i = 1; i < jacob.size(); ++i)
    {
        size_t limit = std::min(jacob[i], small.size());
        for (size_t j = limit; j > prev; --j)
            order.push_back(j - 1);
        prev = limit;
        if (limit == small.size())
            break;
    }

    for (size_t i = 0; i < small.size(); ++i)
    {
        int val = small[order[i]];
        std::deque<int>::iterator it = std::lower_bound(big.begin(), big.end(), val);

        big.insert(it, val);
    }

    deque = big;
}

void PmergeMe::mergeInsetionVector(std::vector<int> &vector)
{
    if (vector.size() <= 1)
        return;

    std::vector<int> small;
    std::vector<int> big;

    for (size_t i = 0; i < vector.size() - 1; i+=2)
    {
        int a = vector[i];
        int b = vector[i + 1];

        if (a > b)
        {
            big.push_back(a);
            small.push_back(b);
        }
        else
        {
            big.push_back(b);
            small.push_back(a);
        }
    }

    if (vector.size() % 2 != 0)
        big.push_back(vector.back());

    mergeInsetionVector(big);

    std::deque<size_t> jacob = jacobsthal_sequence(small.size());
    std::deque<size_t> order;
    size_t prev = 0;

    for (size_t i = 1; i < jacob.size(); ++i)
    {
        size_t limit = std::min(jacob[i], small.size());
        for (size_t j = limit; j > prev; --j)
            order.push_back(j - 1);
        prev = limit;
        if (limit == small.size())
            break;
    }

    for (size_t i = 0; i < small.size(); ++i)
    {
        int val = small[order[i]];
        std::vector<int>::iterator it = std::lower_bound(big.begin(),big.end(),val);

        big.insert(it, val);
    }

    vector = big;
}

void PmergeMe::sort()
{
    clock_t begin_deq = clock();
    mergeInsertionDeque(_deq);
    clock_t end_deq = clock();

    double time_deq = 1000 * static_cast<double>(end_deq - begin_deq)/ CLOCKS_PER_SEC;
    std::cout << "Time to sort a deque of size: " << _deq.size() << "\n\t" << time_deq << " ms." << std::endl;
    clock_t begin_vec = clock();
    mergeInsetionVector(_vec);
    clock_t end_vec = clock();

    double time_vec = 1000 * static_cast<double>(end_vec - begin_vec) / CLOCKS_PER_SEC;
    std::cout << "Time to sort a vector of size: " << _vec.size() << "\n\t" << time_vec << " ms." << std::endl;

}


std::ostream& operator<<(std::ostream &os, PmergeMe &obj) {
    std::deque<int>::iterator it;
    std::vector<int>::iterator vec;
    os << "Deque: " << std::endl;
    for (it = obj.getDeque().begin(); it != obj.getDeque().end(); ++it) {
        os << *it << " ";
    }
    os << std::endl << "Vector: " << std::endl;
    for (vec = obj.getVector().begin(); vec != obj.getVector().end(); ++vec)
    {
        os << *vec << " ";
    }

    return os;
}