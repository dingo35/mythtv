#ifndef STATUSBOX_H_
#define STATUSBOX_H_

#include "mythwidgets.h"
#include "mythdialogs.h"
#include "uitypes.h"
#include "xmlparse.h"

class LayerSet;

class StatusBox : public MythDialog
{
    Q_OBJECT
  public:
    StatusBox(MythMainWindow *parent, const char *name = 0);
   ~StatusBox(void);

  protected slots:

  protected:
    void keyPressEvent(QKeyEvent *e);
    void paintEvent(QPaintEvent *e);

  private:
    void updateTopBar();
    void updateSelector();
    void updateContent();
    void LoadTheme();
    void doListingsStatus();
    void doTunerStatus();
    void doDVBStatus();
    void doLogEntries();
    void clicked();
    void setHelpText();

    XMLParse *theme;
    QDomElement xmldata;
    QRect TopRect, SelectRect, ContentRect;
    UITextType *heading, *helptext, *text_area;
    UIListType *icon_list, *list_area;
    LayerSet *selector, *topbar, *content;

    int max_icons;
};

#endif
