//---------------------------------------------------------------------------

#ifndef uGraphicObjectsH
#define uGraphicObjectsH

#include <Vcl.Graphics.hpp>
#include <string>

class Arrow{
public:
	Arrow() = delete;
	Arrow(TPoint const & pnt, int l, int w, int ang);
	void draw(TCanvas* cnvs);
private:
	TPoint pnt_;
	int l_; //total length of arrow
	int w_; // half of width of arrow head
	int ang_;//rotation in clockwise direction in degree around the arrow tip
};

class Dimension{
public:
	Dimension() = delete;
	Dimension(TPoint const &  pnt_l, TPoint const &  pnt_r, std::string const & str, int offset, int ang);
	void draw(TCanvas* cnvs);
private:
	TPoint pnt_l_;
	TPoint pnt_r_;
	std::string str_; //string above the dim line
	int offset_;
	int ang_;//rotation in clockwise direction in degree around the first point of dimension attachment
};
//---------------------------------------------------------------------------
#endif
