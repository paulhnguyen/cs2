/*
 * Implementation for Chromosome class
 */

#include <algorithm>
#include <cassert>
#include <random>
#include <vector> 


#include "chromosome.hh"

//////////////////////////////////////////////////////////////////////////////
// Generate a completely random permutation from a list of cities
Chromosome::Chromosome(const Cities* cities_ptr)
  : cities_ptr_(cities_ptr),
    order_(random_permutation(cities_ptr->size())),
    generator_(rand())
{
  assert(is_valid()); // fails the size !=0 statement 
}

//////////////////////////////////////////////////////////////////////////////
// Clean up as necessary
Chromosome::~Chromosome()
{
  assert(is_valid());
}

//////////////////////////////////////////////////////////////////////////////
// Perform a single mutation on this chromosome; pick two points in the permutation at random and swap their values.
void
Chromosome::mutate()
{
  // Add your implementation here
  std::uniform_int_distribution<> distrib(0, order_.size()-1);
  unsigned int int1 = distrib(generator_);
  unsigned int int2 = distrib(generator_);
  while (int1 == int2)
  {
    int2 = distrib(generator_);
  }
  std::swap(order_[int1],order_[int2]);
  assert(is_valid());
}

//////////////////////////////////////////////////////////////////////////////
// Return a pair of offsprings by recombining with another chromosome
// Note: this method allocates memory for the new offsprings
std::pair<Chromosome*, Chromosome*>
Chromosome::recombine(const Chromosome* other)
{
  assert(is_valid());
  assert(other->is_valid());

  // Add your implementation here
  std::uniform_int_distribution<> distrib_b(0, order_.size()-1);
  unsigned int b = distrib_b(generator_);
  std::uniform_int_distribution<> distrib_e(b, order_.size()-1);
  unsigned int e = distrib_e(generator_);

  Chromosome* child1 = create_crossover_child(this, other, b, e);
  Chromosome* child2 = create_crossover_child(other, this, b, e);
  std::pair<Chromosome*, Chromosome*> child_pair = std::make_pair(child1, child2);
  return child_pair;
}

//////////////////////////////////////////////////////////////////////////////
// For an ordered set of parents, return a child using the ordered crossover.
// The child will have the same values as p1 in the range [b,e),
// and all the other values in the same order as in p2.
Chromosome*
Chromosome::create_crossover_child(const Chromosome* p1, const Chromosome* p2,
                                   unsigned b, unsigned e) const
{
  Chromosome* child = p1->clone();

  // We iterate over both parents separately, copying from parent1 if the
  // value is within [b,e) and from parent2 otherwise
  unsigned i = 0, j = 0;

  for ( ; i < p1->order_.size() && j < p2->order_.size(); ++i) {
    if (i >= b and i < e) {
      child->order_[i] = p1->order_[i];
    }
    else { // Increment j as long as its value is in the [b,e) range of p1
      while (p1->is_in_range(p2->order_[j], b, e)) {
        ++j;
        assert(j < p2->order_.size());
      }
      child->order_[i] = p2->order_[j];
      j++;
    }
  }
  
  assert(child->is_valid());

  return child;
}

// Return a positive fitness value, with higher numbers representing
// fitter solutions (shorter total-city traversal path).
double
Chromosome::get_fitness() const
{
  return 1 / cities_ptr_->total_path_distance(order_); //reciprocal of total path distance will be smaller if total distance is large
}

// A chromsome is valid if it has no repeated values in its permutation,
// as well as no indices above the range (length) of the chromosome.
bool
Chromosome::is_valid() const
{
  Cities::permutation_t v1 = order_;
  if (order_.size()!= cities_ptr_->size()){
    return false;
  }
  for (size_t i = 0; i < order_.size()-1; i++)
  {
    unsigned int count = std::count(order_.begin(), order_.end(), i);
    if (count != 1)
    {
      return false;
    }
  }
  return true;
}

// Find whether a certain value appears in a given range of the chromosome.
// Returns true if value is within the specified the range specified
// [begin, end) and false otherwise.
bool
Chromosome::is_in_range(unsigned value, unsigned begin, unsigned end) const
{
  std::vector<unsigned int> vec_check;
  unsigned i = begin;
  
  while (i != end)
  {
    vec_check.push_back(order_[i] == value);
    i++;
  }
  unsigned sum_of_elems = std::accumulate(vec_check.begin(), vec_check.end(), 0);
  return(sum_of_elems != 0);
}
