//---------------------------------------------------------------------------

#ifndef uGraphicObjectsH
#define uGraphicObjectsH

#include <Vcl.Graphics.hpp>
#include <string>
#include <vector>
#include <array>



class Arrow{
public:
	Arrow();
	Arrow(int l, int w);
	Arrow(TColor col);
	Arrow(int l, int w, TColor col);
	void draw(TCanvas* const cnvs, TPoint const & pnt, int ang);
private:
	int l_ = 15; //total length of arrow
	int w_ = 4; // half of width of arrow head
	TColor col_ = clBlack;
};
class CoordSyst{
public:
	CoordSyst() = delete;
	CoordSyst(TPoint const & orig);
	void draw(TCanvas* const cnvs);
private:
	TPoint orig_;
	int ax_len_ = 40;
	int orig_rad_ = 4;
	Arrow ar_ {20, 4};

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
