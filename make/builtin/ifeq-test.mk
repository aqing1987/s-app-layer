#IB="YY"

all:

ifeq ($(IB),)
	@echo "IB is empty"
else
	@echo "IB is $(IB)"
endif
