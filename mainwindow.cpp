#include <mainwindow.h>
#include <QtWidgets>
 
#include <mainwindow.h>
#include <QtWidgets>
 
MainWindow::MainWindow(){
	resize(630,300);
	setWindowTitle("gallery");
	QFont buttonFont("Time", 10, QFont::Bold);
	
	textLabel = new QLabel(this);
	textLabel->setGeometry(300,260,320,30);
	textLabel->setText(imgPath);
	textLabel->setFont(QFont("Time",10,QFont::Bold));
	
	openButton = new QPushButton("Open",this);
	openButton->setGeometry(450,180,100,50);
	openButton->setFont(buttonFont);
	
connect (openButton, &QPushButton::clicked,this, &MainWindow::openButtonClick);}
	
void MainWindow::openImage(const QString & path){
	imgPath=path;
	if (imgPath.isNull()){
		imgPath=QFileDialog::getOpenFileName(this,"Open Image"," ","Image Files(*.png *.jpg *.bmp) ");}
	if (!imgPath.isEmpty()){
		if (!pixmap.load(imgPath)){
			QMessageBox::warning(this,"Open Image","The img file could not be loaded.", QMessageBox::Cancel);
	return;}}
	textLabel->setText(imgPath);
}
	
	
void MainWindow::paintEvent(QPaintEvent *){
	QPainter painter(this);
	pixmap.load(imgPath);
	painter.drawPixmap(0,0,pixmap);
	painter.restore();}
	
void MainWindow::openButtonClick(){
	imgPath = textLabel->text();
	openImage();
	update();}





