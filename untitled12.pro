TEMPLATE = subdirs
SUBDIRS = app \
	core \
    test

app.depends = core
test.depends = core
