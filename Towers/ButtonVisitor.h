/**
 * \file ButtonVisitor.h
 *
 * \author Justin Vesche
 *
 * Class that visits the go button.
 */

#pragma once
#include "ItemVisitor.h"

 /** This class is used as a button clicker. */
class CButtonVisitor :
    public CItemVisitor
{
public:
    /**
    * Constructor for CButtonVisitor
    * default for now
    */
    CButtonVisitor() {};

    void VisitGoButton(CGoButton* button);

    /**
    * getter for mGoClicked
    *
    * \return mGoClicked either true or false if the button was clicked
    */
    bool IsButton() { return mGoClicked; }

private:
    /// member that stores if button is clicked, default false.
    bool mGoClicked = false;

};

