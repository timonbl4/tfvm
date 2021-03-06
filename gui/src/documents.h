#ifndef CDOCUMENTSWIDGET_H
#define CDOCUMENTSWIDGET_H

#include <QtWidgets/QTabWidget>

namespace nVirtualMachine
{

namespace nGui
{

class cDocumentWidget;

class cDocumentsWidget : public QTabWidget
{
	Q_OBJECT

public:
	cDocumentsWidget();

	void newDocument();
	bool open(const QString& filePath);
	bool save();
	bool saveAs();
	bool saveAllDocuments();
	bool closeAllDocuments();

	void undo();
	void redo();

Q_SIGNALS:
	void currentDocumentChanged(cDocumentWidget* documentWidget);

protected:
	virtual cDocumentWidget* createDocument() = 0;

private:
	std::map<QString, cDocumentWidget*> filePaths;
};

}

}

#endif // CDOCUMENTSWIDGET_H
