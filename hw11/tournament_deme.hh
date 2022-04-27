#include "deme.hh"
#include <cassert>


class TournamentDeme : public Deme{
    public:
    TournamentDeme(const Cities* cities_ptr, unsigned pop_size, double mut_rate)
    : Deme(cities_ptr, pop_size, mut_rate)
    {};

    virtual Chromosome* tourney_select();
    


};