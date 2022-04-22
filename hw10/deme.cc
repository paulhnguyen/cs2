/*
 * Declarations for Deme class to evolve a genetic algorithm for the
 * travelling-salesperson problem.  A deme is a population of individuals.
 */

#include "chromosome.hh"
#include "deme.hh"

// Generate a Deme of the specified size with all-random chromosomes.
// Also receives a mutation rate in the range [0-1].
Deme::Deme(const Cities* cities_ptr, unsigned pop_size, double mut_rate)
: mut_rate_(mut_rate), generator_(rand())
{
  // Add your implementation here
  while (pop_.size() < pop_size)
  {
    pop_.push_back(new Chromosome(cities_ptr));
  }
  

}

// Clean up as necessary
Deme::~Deme()
{
  for (auto chrom : pop_) 
  {
    delete chrom;
  } 
}

// Evolve a single generation of new chromosomes, as follows:
// We select pop_size/2 pairs of chromosomes (using the select() method below).
// Each chromosome in the pair can be randomly selected for mutation, with
// probability mut_rate, in which case it calls the chromosome mutate() method.
// Then, the pair is recombined once (using the recombine() method) to generate
// a new pair of chromosomes, which are stored in the Deme.
// After we've generated pop_size new chromosomes, we delete all the old ones.
void Deme::compute_next_generation()
{
  std::vector<Chromosome*> kids;
  for (size_t i = 0; i < pop_.size()/2; i++)
  {
    Chromosome* dad = select_parent();
    Chromosome* mom = select_parent();
    std::uniform_real_distribution<> unif_d(0, 1);
    double mutate_check_dad = unif_d(generator_);
    std::uniform_real_distribution<> unif_m(0, 1);
    double mutate_check_mom = unif_m(generator_);
    if (mutate_check_dad < mut_rate_)
    {
      dad->mutate();
    }
    if (mutate_check_mom < mut_rate_)
    {
      mom->mutate();
    }
    std::pair<Chromosome*, Chromosome*> kid_pair = dad->recombine(mom);
    kids.push_back(kid_pair.first);
    kids.push_back(kid_pair.second);
  }
  for (auto chrom : pop_) 
  {
    delete chrom;
  } 
  pop_ = kids;
}

// Return a copy of the chromosome with the highest fitness.
const Chromosome* Deme::get_best() const
{
  Chromosome* best_chrome = pop_[0];
  for (size_t i = 0; i < pop_.size()-1; i++)
  {
    double best_fitness = best_chrome->get_fitness();
    if (pop_[i]->get_fitness() > best_fitness)
    {
      best_chrome = pop_[i];
    }
  }
  return best_chrome;
  
}

// Randomly select a chromosome in the population based on fitness and
// return a pointer to that chromosome.
Chromosome* Deme::select_parent()
{
  double total_fitness = 0;
  for (size_t i = 0; i < pop_.size()-1; i++)
  {
    total_fitness = total_fitness + pop_[i]->get_fitness();
  }
  std::vector<double> fitness_probs;
  for (size_t i = 0; i < pop_.size()-1; i++)
  {
    fitness_probs.push_back(pop_[i]->get_fitness() / total_fitness);
  }
  std::discrete_distribution<> discrete_gen(fitness_probs.begin(), fitness_probs.end());
  unsigned index = discrete_gen(generator_);
  return pop_[index];

  
}
