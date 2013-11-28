<?php

/*. require_module 'standard'; .*/

namespace it\icosaedro\phplint;

#require_once __DIR__ . "/../../../autoload.php";
require_once __DIR__ . "/TypeInterface.php";


/**
	Singleton object that represents a generic object instance of any
	class.
	The Types::parseType() method uses this class to represent the result
	of the compilation of a textual type descriptor.
	@author Umberto Salsi <salsi@icosaedro.it>
	@version $Date: 2012/05/06 16:06:42 $
*/
class ObjectType implements TypeInterface {

	private static /*. self .*/ $singleton;

	private /*. void .*/ function __construct(){}

	/**
		Return the instance that represents the object type.
		@return self
	*/
	static function factory()
	{
		if( self::$singleton === NULL )
			self::$singleton = new ObjectType();
		return self::$singleton;
	}


	/**
		Checks if the expression or variable passed is of type object.
		@param mixed $v Any expression or variable.
		@return bool True if the expression is either the NULL value or it is
		an object.
	*/
	function check($v)
	{
		return $v === NULL or is_object($v);
	}


	/**
		Returns the descriptor of this type, that is "object".
		@return string The string "object".
	*/
	function __toString()
	{
		return "object";
	}

}
