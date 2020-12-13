//---------------------------------------------------------------------------

#ifndef uGraphicObjectsH
#define uGraphicObjectsH

#include <Vcl.Graphics.hpp>
#include <string>
#include <vector>
#include <array>
class Line{
public:
	Line() = delete;
	Line(TCanvas* cnvs);
	Line(TCanvas* cnvs, TColor col);
	void draw(TPoint const & p1, TPoint const & p2);
private:
	static int const last_pnt_index_ = 1;
	TColor col_ {clBlack};
	TCanvas* const cnvs_;
};


class Arrow{
public:
	Arrow() = delete;
	Arrow(TCanvas* cnvs, int l, int w);
	Arrow(TCanvas* cnvs, TColor col);
	Arrow(TCanvas* cnvs, int l, int w, TColor col);
	void draw(TPoint const & pnt, int ang);
private:
	TCanvas* const cnvs_;
	int l_ {15}; //total length of arrow
	int w_ {4}; // half of width of arrow head
	TColor col_ {clBlack};
};
class CoordSyst{
public:
	CoordSyst() = delete;
	CoordSyst(TCanvas* const cnvs);
	CoordSyst(TCanvas* cnvs, TColor ax_col, TColor orig_color);
	void draw(TPoint const & orig);
private:
	TCanvas* const cnvs_;
	TColor ax_col_{clBlack};
	TColor orig_color_{clWhite};
	int ax_len_ {40};
	int orig_rad_ {4};
	Arrow ar_ {cnvs_, ax_col_};

};

class Dimension{
public:
	enum Direct{horiz, vert};
	Dimension() = delete;
	Dimension(TPoint const &  pnt_1,
			  TPoint const &  pnt_2,
			  std::u16string const & str,
			  int offset,
			  Direct dir);
	void draw(TCanvas* cnvs);
private:
	TPoint pnt_1_;
	TPoint pnt_2_;
	std::u16string str_; //string above the dim line
	int offset_{10};
	int const ext_ {2};
	int const tick_cathet_ {4};
	Direct dir_;
    int txt_offset_{2};
	void draw_vert(TCanvas* cnvs);
	void draw_horiz(TCanvas* cnvs);
};

//rotation in clockwise direction in degree around the first point of dimension attachment
//---------------------------------------------------------------------------
#endif
