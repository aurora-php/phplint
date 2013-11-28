# The PHPLint program:
PHPLINT = /home/salsi/src/phplint/src/phplint
# Dir. of PHPLint standard modules:
MODULES = /home/salsi/src/phplint/modules

all:
	#  make test      Performs internal tests, generates *.success files
	#                 for every module passing the test.
	#
	#  make doc       Generate *.html files (requires PHPLint).
	#
	#  make clean     Remove generated files.

test: \
	test-BigInt.success \
	test-BigFloat.success \
	test-ExprEval.success

test-BigInt.success: BigInt.php test-BigInt.php
	@echo "BigInt.php: running test..."
	./test-BigInt.php
	touch test-BigInt.success
	@echo "BigInt.php: test passed."
	
test-BigFloat.success: test-BigInt.success BigFloat.php test-BigFloat.php
	./test-BigFloat.php
	touch test-BigFloat.success

test-ExprEval.success: test-BigFloat.success ExprEval.php test-ExprEval.php
	./test-ExprEval.php
	touch test-ExprEval.success

%.htm: %.php
	# Now building $@...
	@$(PHPLINT) \
		--modules-path $(MODULES) \
		--print-context \
		--no-report-unused \
		--no-print-notices \
		--doc-ref-remap $(MODULES)/ \
			http://www.icosaedro.it/phplint/modules.cgi?module= \
		--doc \
		--doc-extension .htm \
		$< || (rm -f $@ && false)

doc: BigInt.htm BigFloat.htm ExprEval.htm

clean:
	rm -f *.success *.htm

