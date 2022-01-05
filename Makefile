CXX=g++
CXXFLAGS=-I. -lstdc++


# =============================================================================================================
#
# BUILD
#
# =============================================================================================================

codeorient:
	@echo " "
	@echo "------------------------------------------------------------"
	@echo "TEE CONFIGURATION: BUILD "
	@echo "------------------------------------------------------------"
	@echo " "
	
	make Tee


# =============================================================================================================
#
# BUILD TEE
#
# =============================================================================================================

Tee: Tee.cpp main.cpp
	$(CXX) -o main Tee.cpp main.cpp  $(CXXFLAGS)
	
