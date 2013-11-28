<?php

namespace it\icosaedro\io;
require_once __DIR__ . "/../../../autoload.php";
require_once __DIR__ . "/../../../errors.php";
use ErrorException;
use it\icosaedro\io\InputStream;
use it\icosaedro\io\IOException;
use it\icosaedro\io\FileName;
use it\icosaedro\utils\UString;

/**
 * Reads a file as a stream of bytes.
 *
 * @author Umberto Salsi <salsi@icosaedro.it>
 * @version $Date: 2012/03/17 17:10:42 $
 */
class FileInputStream extends InputStream {

	private /*. resource .*/ $f;


	/**
	 * Opens the specified file for reading.
	 * @param UString $name Name of the file, possibly with path.
	 * @return void
	 * @throws IOException Invalid file name. File name or its path contains
	 * characters that cannot be mapped to the current system locale. Access
	 * denied to the file or to some part of the path.
	 */
	function __construct($name) {
		try {
			$this->f = fopen(FileName::encode($name), "rb");
		}
		catch(ErrorException $e){
			throw new IOException($e->getMessage());
		}
	}


	/**
	 * Factory method that opens the specified file for reading.
	 * @param string $name File name encoded using the current system locale.
	 * @return self Reader object.
	 * @throws IOException Invalid file name. File name or its path contains
	 * characters that cannot be mapped to the current system locale. Access
	 * denied to the file or to some part of the path.
	 */
	static function newByString($name) {
		return new self(FileName::decode($name));
	}


	/**
	 * Reads one byte.
	 * @return int Byte read in [0,255], or -1 on end of file.
	 * @throws IOException
	 */
	function readByte() {
		try {
			$b = fread($this->f, 1);
		}
		catch(ErrorException $e){
			throw new IOException($e->getMessage());
		}
		if( $b === FALSE )
			return -1;
		return ord($b);
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
	function readBytes($n) {
		if( $n <= 0 )
			return "";

		try {
			$bytes = fread($this->f, $n);
		}
		catch(ErrorException $e){
			throw new IOException($e->getMessage());
		}
		if( $bytes === FALSE or strlen($bytes) == 0 )
			return NULL;
		else
			return $bytes;
	}


	/**
	 * Closes the file. Does nothing if already closed.
	 * Once closed, this object cannot be used anymore.
	 * @return void
	 * @throws IOException
	 */
	function close() {
		if( $this->f !== NULL ){
			try {
				fclose($this->f);
			}
			catch(ErrorException $e){
				throw new IOException($e->getMessage());
			}
			$this->f = NULL;
		}
	}


	/*. void .*/ function __destruct(){
		try {
			$this->close();
		}
		catch(IOException $e){}
	}

}
