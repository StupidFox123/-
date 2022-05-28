#include <QtWidgets>
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class MainWindow : public QMainWindow{
	public:
		MainWindow();
		void openButtonClick();
		void openImage(const QString & path=QString() );
	protected:
		void paintEvent(QPaintEvent *event);
	private:
		QLabel *textLabel;
		QPushButton *openButton;
		QLineEdit *pathEdit;
		QPainter *painter;
		QPixmap pixmap;
		QString imgPath;
	};		
	
#endif
