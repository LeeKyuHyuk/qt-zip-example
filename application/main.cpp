#include <QtCore>
#include <zip.h>
#include "main.h"

int main(int argc, char *argv[]) {
    if (argc == 2) {
        struct zip_t *zip = zip_open(argv[1], 0, 'r');
        int entriesNumber = zip_total_entries(zip);
        zip_extract(argv[1], QString(argv[1]).section(".", 0, 0).toStdString().c_str(), extractAll, &entriesNumber);
    }
    pause();
    return EXIT_SUCCESS;
}

int extractAll(const char *filename, void *arg) {
    static int i = 0;
    int n = *(int *)arg;
    printf("Extracted: %s (%d of %d)\n", QFileInfo(filename).fileName().toStdString().c_str(), ++i, n);
    return EXIT_SUCCESS;
}

void pause() {
    do {
        qInfo("Press <RETURN> to close this window...");
    } while (getchar() != '\n');
}
