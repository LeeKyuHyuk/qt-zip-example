TEMPLATE = subdirs

SUBDIRS += \
    application \
    zip

application.depends = zip
