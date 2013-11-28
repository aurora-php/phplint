<?php

namespace it\icosaedro\io;
require_once __DIR__ . "/../../../autoload.php";
/*. require_module 'standard'; .*/

/**
 * Reads a buffer of bytes from memory using the InputStream interface.
 *
 * @author Umberto Salsi <salsi@icosaedro.it>
 * @version $Date: 2012/03/17 17:10:42 $
 */
class BufferInputStream extends InputStream {

	private /*. string .*/ $buffer;
	private $cursor = 0;


	/**
	 * Creates the buffer to be read.
	 * @param string $buffer Buffer of bytes to read.
	 * @return void
	 */
	function __construct($buffer){
		$this->buffer = $buffer;
		$this->cursor = 0;
	}


	/**
	 * Reads one byte.
	 * @return int Byte read in [0,255], or -1 on end of file.
	 * @throws IOException
	 */
	function readByte(){
		if( $this->cursor >= strlen($this->buffer) )
			return -1;
		return ord($this->buffer[ $this->cursor++ ]);
	}


	/**
	 * Reads several bytes.
	 * @param int $n Maximum number of bytes to read.
	 * @return string Bytes read, possibly in a number less than requested,
	 * either because the end of the file has been reached, or the input
	 * buffer is short but still data are available. If $n <= 0 does nothing
	 * and the empty string is returned. If $n > 0 and the returned string
	 * is NULL, the end of the file is reached.
	 * @throws IOException
	 */
	function readBytes($n)
	{
		if( $n <= 0 )
			return "";

		if( $this->cursor >= strlen($this->buffer) )
			return NULL;

		$a = $this->cursor;
		$b = $a + $n;
		# Check overflow:
		if( is_float($b) )
			$b = PHP_INT_MAX;
		if( $b > strlen($this->buffer) )
			$b = strlen($this->buffer);

		$res = substr($this->buffer, $a, $b - $a);
		$this->cursor = $b;
		return $res;
	}


	/**
	 * Skip bytes.
	 * @param int $n Number of bytes to skip. Does nothing if this number
	 * is <= 0.
	 * @return void
	 * @throws IOException
	 */
	function skip($n)
	{
		if( $n <= 0 )
			return;
		$c = $this->cursor + $n;
		if( is_float($c) or $c > strlen($this->buffer) )
			throw new IOException("beyond end of file");
		$this->cursor = $c;
	}


	/**
	 * Closes the stream. Does nothing if the stream has been already closed.
	 * @return void
	 * @throws IOException
	 */
	function close(){}

}
