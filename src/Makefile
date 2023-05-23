all: FactorialBlk_TB.sv FactorialBlk.sv
	iverilog -y . -Y .sv -g2012 -o simul.iverout FactorialBlk_TB.sv
	@vvp simul.iverout -lxt2

clean:
	rm *.iverout