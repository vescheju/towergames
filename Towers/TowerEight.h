#pragma once
#include "Tower.h"
class CTowerEight :
	public CTower
{
public:
	/// constructor
	CTowerEight(CGame* game);

	/// Default constructor (disabled)
	CTowerEight() = delete;

	/// Copy constructor (disabled)
	CTowerEight(const CTowerEight&) = delete;

	/**Saves item to XMLNode
	*\param node
	*\returns itemNode
	*/
	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

private:

};

