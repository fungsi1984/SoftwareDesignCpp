#ifndef COSTREPORT_H_
#define COSTREPORT_H_

#include "ProvisionGroup.h"
#include "Sunscreen.h"

class CostReport
{
public:
    CostReport();
    ~CostReport();

    void generate_report();

private:
    ProvisionGroup provisions;

    Equipment *equipment;
    Uniform   *uniform;
    Footwear  *footwear;
    Sunscreen *sunscreen;
};

#endif /* COSTREPORT_H_ */
