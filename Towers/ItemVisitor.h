/**
 * \file ItemVisitor.h
 *
 * \author Ian Masterson
 *
 * The Item Visitor base class
 */


#pragma once

 // Forward references to all item types
class CItemHouse;
class CItemOpen;
class CItemRoad;
class CItemTree;
class CBalloonRed;
class CRedBombTower;
class CPumpkinTower;
class CTowerEight;
class CRingTower;
class CRing;
class CDart;
class CRedExplosion;
class CPumpkinExplosion;
class CGoButton;
class CGameMenu;
class CScoreboard;
class CBalloonBoss;
class CItemFog;

/** Tile visitor base class */
class CItemVisitor
{
public:
    virtual ~CItemVisitor() {}

    /** 
     * Visit a CItemHouse object
     * \param house House we are visiting 
     */
    virtual void VisitHouse(CItemHouse* house) {}

    /**
     * Visit a CItemOpen object
     * \param open Open item we are visiting
     */
    virtual void VisitOpen(CItemOpen* open) {}

    /**
     * Visit a CItemRoad object
     * \param road Road item we are visiting
     */
    virtual void VisitRoad(CItemRoad* road) {}

    /**
     * Visit a CItemTree object
     * \param tree Tree item we are visiting
     */
    virtual void VisitTree(CItemTree* tree) {}

    /**
     * Visit a CBalloonRed object
     * \param balloon BalloonRed item we are visiting
     */
    virtual void VisitBalloonRed(CBalloonRed* balloon) {}

    /**
     * Visit a CRedBombTower object
     * \param bomb Bomb tower we are visiting
     */
    virtual void VisitRedBombTower(CRedBombTower* bomb) {}

    /**
     * Visit a CPumpkinTower object
     * \param bomb Bomb tower we are visiting
     */
    virtual void VisitPumpkinTower(CPumpkinTower* bomb) {}

    /**
     * Visit a CTowerEight object
     * \param eight Eight tower we are visiting
     */
    virtual void VisitTowerEight(CTowerEight* eight) {}

    /**
     * Visit a CRingTower object
     * \param ringTower Ring tower we are visiting
     */
    virtual void VisitRingTower(CRingTower* ringTower) {}

    /**
     * Visit a CRing object
     * \param ring Ring we are visiting
     */
    virtual void VisitRing(CRing* ring) {}

    /**
     * Visit a CDart object
     * \param dart Dart we are visiting
     */
    virtual void VisitDart(CDart* dart) {}

    /**
     * Visit a CRedExplosion object
     * \param explosion Explosion we are visiting
     */
    virtual void VisitRedExplosion(CRedExplosion* explosion) {}

    /**
     * Visit a CPumpkinExplosion object
     * \param explosion Explosion we are visiting
     */
    virtual void VisitPumpkinExplosion(CPumpkinExplosion* explosion) {}

    /**
     * Visit a CGoButton object
     * \param button Button we are visiting
     */
    virtual void VisitGoButton(CGoButton* button) {}

    /**
    * Visit a CGameMenu object
    * \param menu The menu we are visiting
    */
	virtual void VisitMenu(CGameMenu* menu) {}

    /**
    * Visit a CScoreboard object
    * \param score The scoreboard we are visiting
    */
	virtual void VisitScoreBoard(CScoreboard* score) {}

    /**
     * Visit a CBalloonBoss object
     * \param balloon BalloonBoss item we are visiting
     */
    virtual void VisitBalloonBoss(CBalloonBoss* balloon) {}

    /**
     * Visit a CFog object
     * \param fog CItemFog item we are visiting
     */
    virtual void VisitFog(CItemFog* fog) {}
};

