
LDFLAGS := -l ~/include


%.sh:
	./%


scrollword: camscrollword taunt
	echo "Target : $@"
	echo "First prereq $<"
	echo "All prereqs $^"

test: test.sh
	./test.sh
