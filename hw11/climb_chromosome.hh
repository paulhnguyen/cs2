#pragma once

#include <cassert>
#include <iostream>
#include "chromosome.hh"


class ClimbChromosome : public Chromosome {
    ClimbChromosome(const ClimbChromosome&) = delete;
    ClimbChromosome(ClimbChromosome&&) = delete;
    ClimbChromosome& operator=(const ClimbChromosome&) = delete;
    ClimbChromosome& operator=(ClimbChromosome&&) = delete;

    public:
    ClimbChromosome(const Cities* cities_ptr)
    : Chromosome(cities_ptr)
    {};
    virtual ~ClimbChromosome(){
        assert(is_valid());
    }

    virtual void mutate() override;

    virtual Chromosome* clone() const override{
        assert(is_valid());
        return new ClimbChromosome(cities_ptr_);
    }
};