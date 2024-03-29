//
//      
//  (c) Stan Melax 1998-2007
//
// this module implements an object layer above bsp's, geometry, and mesh classes so 
// we can load, save, edit, interact, and otherwise work with them within a 3d application.
//
// a "brush" object is static geometry (not a simulated rigidbody).
// i'm not too attached to this.  could probably throw this design away and start fresh.


#ifndef SM_BRUSH_H
#define SM_BRUSH_H

#include "array.h"
#include "bsp.h"
#include "smstring.h"
#include "object.h"

class Model;
class Brush : public Entity
{
public:
	// from Entity: String name;
	BSPNode *bsp;
	float3 position;
	float3 positionold;
	float3 position_start;
	float3 velocity;
	Model *model;
	int draw;
	int highlight;
	Brush(const char *_name);
	~Brush();
	float3 bmin,bmax;
	int shadowcast; 
	void Modified();
	String filename;
	int collide;
	int mergeable;
	int playerinside;
	String onenter;
	String onexit;
	String onclick;
	String message;
	String hud;
	int bspclip;
};

void   Retool(Brush *brush);
void   ReCompile(Brush *brush);
Brush *BrushLoad(String filename,String path=String(""));
void   BrushSave(Brush *brush,String filename);
extern Array<Brush*> Brushes;
Brush* BrushFind(String name);

#endif
