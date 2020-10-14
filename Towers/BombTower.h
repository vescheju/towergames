#pragma once
#include "Tower.h"
class CBombTower :
	public CTower
{
public:
	/// constructor
	CBombTower(CGame* game);

	/// Default constructor (disabled)
	CBombTower() = delete;

	/// Copy constructor (disabled)
	CBombTower(const CBombTower&) = delete;

	/**Saves item to XMLNode
	*\param node
	*\returns itemNode
	*/
	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

private:

};

