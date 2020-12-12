//---------------------------------------------------------------------------

#ifndef uGraphicObjectsH
#define uGraphicObjectsH

#include <Vcl.Graphics.hpp>
#include <string>
#include <vector>
#include <array>



class Arrow{
public:
	Arrow() = delete;
	Arrow(TPoint const & pnt, int l, int w, int ang);
	void draw(TCanvas* cnvs);
private:
	TPoint pnt_;//arrow tip location
	int l_; //total length of arrow
	int w_; // half of width of arrow head
	int ang_;//rotation in clockwise direction in degree around the arrow tip
};

class Dimension{
public:
	enum Direct{horiz, vert};
	Dimension() = delete;
	Dimension(TPoint const &  pnt_1,
			  TPoint const &  pnt_2,
			  std::string const & str,
			  int offset,
			  Direct dir);
	void draw(TCanvas* cnvs);
private:
	TPoint pnt_1_;
	TPoint pnt_2_;
	std::string str_; //string above the dim line
	int offset_;
	Direct dir_;
	void draw_vert(TCanvas* cnvs);
	void draw_horiz(TCanvas* cnvs);
};

//rotation in clockwise direction in degree around the first point of dimension attachment
//---------------------------------------------------------------------------
#endif
