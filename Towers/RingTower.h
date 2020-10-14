#pragma once
#include "Tower.h"
class CRingTower :
	public CTower
{
public:
	/// constructor
	CRingTower(CGame* game);

	/// Default constructor (disabled)
	CRingTower() = delete;

	/// Copy constructor (disabled)
	CRingTower(const CRingTower&) = delete;

	/**Saves item to XMLNode
	*\param node
	*\returns itemNode
	*/
	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

private:

};

