
#include <iostream>
#include "vision.h"
#include "mov.h"
int main()
{
	cv::Mat matriz_calibrada = Mat::eye(3, 3, CV_64F);
	Mat DCoeficientes;
	//calibrador(cameraMatrix, distanceCoefficients);
	Cargar_Calibracion("calibrado", matriz_calibrada, DCoeficientes);
	Mat Matriz_Camara;
	vector<int> aruco_IDs;
	vector<vector<Point2f>> marcador_Esquinas, rejectedCandidates;
	aruco::DetectorParameters parametros;
	Ptr < aruco::Dictionary> DiccionarioMarcadores = aruco::getPredefinedDictionary(aruco::PREDEFINED_DICTIONARY_NAME::DICT_4X4_50);
	VideoCapture Vcapturador(0);

	if (!Vcapturador.isOpened()) {
		return 0;
	}
	namedWindow("Webcam", CV_WINDOW_NORMAL);
	vector<Vec3d> vectores_rotacion, vectores_translacion;
	int paso = 0;
	while (1) {
		paso++;
		if (!Vcapturador.read(Matriz_Camara)) {
			break;
		}
		aruco::detectMarkers(Matriz_Camara, DiccionarioMarcadores, marcador_Esquinas, aruco_IDs);
		aruco::estimatePoseSingleMarkers(marcador_Esquinas, Tamano_Aruco_cuadrado, matriz_calibrada, DCoeficientes, vectores_rotacion, vectores_translacion);
		aruco::drawDetectedMarkers(Matriz_Camara, marcador_Esquinas, aruco_IDs);

		for (int i = 0; i < aruco_IDs.size(); i++) {
			std::vector<std::vector<double>> v(vectores_translacion.size(), std::vector<double>(3));
			for (size_t j = 0; i < vectores_translacion.size(); ++i)
			{
				const cv::Vec3d& c = vectores_translacion[i];
				switch (paso)
				{
				case 1:
					Matriz_Camara = Fotograma("f1.jpg", marcador_Esquinas, Matriz_Camara, "1");
					break;
				case 2:
					Matriz_Camara = Fotograma("f2.jpg", marcador_Esquinas, Matriz_Camara, "2");
					break;
				case 3:
					Matriz_Camara = Fotograma("f3.jpg", marcador_Esquinas, Matriz_Camara, "3");
					break;
				case 4:
					Matriz_Camara = Fotograma("f4.jpg", marcador_Esquinas, Matriz_Camara, "4");
					break;
				case 5:
					Matriz_Camara = Fotograma("f5.jpg", marcador_Esquinas, Matriz_Camara, "5");
					break;
				case 6:
					Matriz_Camara = Fotograma("f6.jpg", marcador_Esquinas, Matriz_Camara, "6");
					break;
				case 7:
					Matriz_Camara = Fotograma("f7.jpg", marcador_Esquinas, Matriz_Camara, "7");
					break;
				case 8:
					Matriz_Camara = Fotograma("f8.jpg", marcador_Esquinas, Matriz_Camara, "8");
					break;
				case 9:
					Matriz_Camara = Fotograma("f9.jpg", marcador_Esquinas, Matriz_Camara, "9");
					break;
				case 10:
					Matriz_Camara = Fotograma("f10.jpg", marcador_Esquinas, Matriz_Camara, "10");
					break;
				case 11:
					Matriz_Camara = Fotograma("f11.jpg", marcador_Esquinas, Matriz_Camara, "11");
					break;
				case 12:
					Matriz_Camara = Fotograma("f12.jpg", marcador_Esquinas, Matriz_Camara, "12");
					break;
				case 13:
					Matriz_Camara = Fotograma("f13.jpg", marcador_Esquinas, Matriz_Camara, "13");
					break;
				case 14:
					Matriz_Camara = Fotograma("f14.jpg", marcador_Esquinas, Matriz_Camara, "14");
					break;
				default :
					paso = 0;
					break;
				}
			}
		}
		imshow("Webcam", Matriz_Camara);
		if (waitKey(50) >= 0) break;

	}
	return 0;
}