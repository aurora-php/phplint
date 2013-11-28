<?php

namespace it\icosaedro\io;
require_once __DIR__ . "/IOException.php";
use it\icosaedro\io\IOException;

/**
 * Input stream of bytes. Possible implementations of this abstract class
 * may provide, for example, access to the file system or to data in memory.
 *
 * @author Umberto Salsi <salsi@icosaedro.it>
 * @version $Date: 2012/03/17 17:10:42 $
 */
abstract class InputStream {


	/**
	 * Reads one byte.
	 * @return int Byte read in [0,255], or -1 on end of file.
	 * @throws IOException
	 */
	abstract function readByte();


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
		$bytes = "";
		while( $n > 0 ){
			$b = $this->readByte();
			if( $b < 0 )
				break;
			$bytes .= chr($b);
		}
		if( $n > 0 and strlen($bytes) == 0 )
			return NULL;
		else
			return $bytes;
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
		$bytes = $this->readBytes($n);
		if( strlen($bytes) < $n )
			throw new IOException("beyond end of file");
	}


	/**
	 * Closes the stream. Does nothing if the stream has been already closed.
	 * @return void
	 * @throws IOException
	 */
	function close(){}

}
