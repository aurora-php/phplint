<?php

namespace it\icosaedro\io;
namespace it\icosaedro\io;
require_once __DIR__ . "/../../../autoload.php";
/*. require_module 'standard'; .*/

/**
 * Writes bytes to a buffer in memory using the OutputStream interface.
 * Example:
 * <pre>
 * $b = new BufferOutputBuffer();
 * $b->writeBytes("xyz");
 * $b->writeBytes("abcd");
 * echo $b->getBuffer(); # ==> xyzabcd
 * </pre>
 *
 * @author Umberto Salsi <salsi@icosaedro.it>
 * @version $Date: 2012/03/17 17:10:42 $
 */
class BufferOutputStream extends OutputStream {

	private /*. string .*/ $buffer = "";


	/*. void .*/ function writeByte(/*. int .*/ $b)
	{
		$this->buffer .= chr($b);
	}


	/*. void .*/ function writeBytes(/*. string .*/ $bytes)
	{
		$this->buffer .= $bytes;
	}


	/**
	 * Does nothing.
	 * @return void
	 */
	function flush(){}


	/**
	 * Does nothing.
	 * @return void
	 */
	function close(){}


	/**
	 * Returns the current buffer filled with the bytes written so far.
	 * @return string Buffer filled with the bytes written so far.
	 */
	function getBuffer(){
		return $this->buffer;
	}
	
}
