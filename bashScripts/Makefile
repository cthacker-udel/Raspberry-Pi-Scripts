

%extreme: %.extreme
	for i in {1..10} ; \
		do \
			echo "1"; \
		done

%.extreme: %
	cp  $< $<.extreme


%z: foo
	echo "Ran z rule"


%: %.c
	echo "original name is not file"


%s: %*
	echo "Target : $@"
	echo "First prereq : $<"
	echo "All prereqs : $^"


clean:
	echo "Target : $@"
	echo "First Prereq : $<"


foo:
	echo "Running the foo rule"
