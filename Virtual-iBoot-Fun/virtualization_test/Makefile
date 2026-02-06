CC = clang
SRCDIR = virtualization_test
SOURCES = $(SRCDIR)/main.m $(SRCDIR)/VMDelegate.m
HEADERS = $(SRCDIR)/VZPrivate.h $(SRCDIR)/VMDelegate.h $(SRCDIR)/Debug.h
TARGET = iBootVirt
ENTITLEMENTS = $(SRCDIR)/virtualization_test.entitlements

CFLAGS = -fobjc-arc -arch arm64
FRAMEWORKS = -framework Foundation -framework Virtualization
LDFLAGS = -undefined dynamic_lookup

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(FRAMEWORKS) $(LDFLAGS) $(SOURCES) -o $(TARGET)

sign: $(TARGET)
	codesign -s - --entitlements $(ENTITLEMENTS) -f $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all sign clean
