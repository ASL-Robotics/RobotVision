sourceDir := $(shell pwd)/src
execName = RobotVision

all:
	cd $(sourceDir)/build && cmake .. && make
	cp $(sourceDir)/build/$(execName) $(execName)
	@echo done
clean:
	rm -f RobotVision
	rm -rf $(sourceDir)/build/*
	@echo done