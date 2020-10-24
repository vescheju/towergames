#pragma once

#include "Balloon.h"
#include "ItemVisitor.h"
#include <vector>

class CLevelProgressor : public CItemVisitor
{
public:
	virtual void VisitBalloonRed(CBalloonRed* balloon) override;
	virtual void VisitBalloonBoss(CBalloonBoss* balloon) override;

	bool GetProgress();

private:
	std::vector<CBalloonRed*> mNumRedBalloons;
	std::vector<CBalloonBoss*> mNumBossBalloons;
};

