#ifndef BOUNCE_H
#define BOUNCE_H
#include "SubAction.h"
class Bounce : public SubAction {
public:
	void update(int delta) override;
	void init() override;
};

#endif