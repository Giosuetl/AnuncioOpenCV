#pragma once

#include <iostream>
#include "vision.h"
Mat Fotograma(const char* file,vector<vector<Point2f>> marcador_Esquinas, Mat Matriz_Camara, const char* numero) {
	Mat im_src = imread(file);
	if (im_src.data == NULL) {
		std::cout << file << ": imagen no encontrada\n" << std::endl;
		return im_src;
	}

	std::vector<Point2f> pts_src, pts_src1;
	pts_src.push_back(Point2f(0, 0));
	pts_src.push_back(Point2f(im_src.cols - 1, 0));
	pts_src.push_back(Point2f(im_src.cols - 1, im_src.rows - 1));
	pts_src.push_back(Point2f(0, im_src.rows - 1));

	std::vector<Point> pts_dst;
	pts_dst.push_back(marcador_Esquinas[0][0]);
	pts_dst.push_back(marcador_Esquinas[0][1]);
	pts_dst.push_back(marcador_Esquinas[0][2]);
	pts_dst.push_back(marcador_Esquinas[0][3]);


	Mat h, h1;
	Mat im_out, im_out1;
	h = findHomography(pts_src, pts_dst);
	warpPerspective(im_src, im_out, h, Matriz_Camara.size());
	cv::putText(Matriz_Camara, numero,
		cv::Point(30, 30),
		cv::FONT_HERSHEY_SIMPLEX, 1, CV_RGB(250, 0, 0), 2);//150
	fillConvexPoly(Matriz_Camara, pts_dst, 0, 16);
	Matriz_Camara = Matriz_Camara + im_out;
	return Matriz_Camara;
}