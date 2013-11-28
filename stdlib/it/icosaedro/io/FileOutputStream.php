<?php

namespace it\icosaedro\io;
require_once __DIR__ . "/../../../errors.php";
require_once __DIR__ . "/../../../autoload.php";
use ErrorException;
use it\icosaedro\io\IOException;
use it\icosaedro\io\OutputStream;
use it\icosaedro\io\FileName;
use it\icosaedro\utils\UString;

/**
 * Writes a file as a stream of bytes.
 *
 * @author Umberto Salsi <salsi@icosaedro.it>
 * @version $Date: 2012/03/17 17:10:42 $
 */
class FileOutputStream extends OutputStream {

	private /*. resource .*/ $f;


	/**
	 * Opens the specified file for writing. Overwrites the file if
	 * it already exists.
	 * @param UString $name Name of the file, possibly with path.
	 * @param bool $append If the file already exists, append new data.
	 * @return void
	 * @throws IOException Invalid file name. File name or its path contains
	 * characters that cannot be mapped to the current system locale. Access
	 * denied to the file or to some part of the path.
	 */
	function __construct($name, $append = FALSE) {
		try {
			$this->f = fopen(FileName::encode($name), $append? "ab" : "wb");
		}
		catch(ErrorException $e){
			throw new IOException($e->getMessage());
		}
	}


	/**
	 * Factory method that opens the specified file for writing.
	 * Overwrites the file if it already exist.
	 * @param string $name File name encoded using the current system locale.
	 * @param bool $append If the file already exists, append new data.
	 * @return self Reader object.
	 * @throws IOException Invalid file name. File name or its path contains
	 * characters that cannot be mapped to the current system locale. Access
	 * denied to the file or to some part of the path.
	 */
	static function newByString($name, $append = FALSE)
		/*. throws IOException .*/
	{
		return new self(FileName::decode($name), $append);
	}


	/**
	 * Writes a single byte.
	 * @param int $b Byte to write. Only the lower 8 bits are actually
	 * written.
	 * @return void
	 * @throws IOException
	 */
	public function writeByte($b) {
		try {
			if( fwrite($this->f, chr($b & 255)) !== 1 )
				throw new IOException("zero bytes written");
		}
		catch(ErrorException $e){
			throw new IOException($e->getMessage());
		}
	}


	/**
	 * Writes a string of bytes. Does nothing if the string is NULL
	 * or empty.
	 * @param string $bytes
	 * @return void
	 * @throws IOException
	 */
	public function writeBytes($bytes) {
		if( strlen($bytes) == 0 )
			return;
		try {
			$n = fwrite($this->f, $bytes);
			if( $n !== strlen($bytes) )
				throw new IOException("only $n bytes written");
		}
		catch(ErrorException $e){
			throw new IOException($e->getMessage());
		}
	}


	public /*. void .*/ function flush()
		/*. throws IOException .*/
	{
		try {
			if( ! fflush($this->f) )
				throw new IOException("flushing failed");
		}
		catch(ErrorException $e){
			throw new IOException($e->getMessage());
		}
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
