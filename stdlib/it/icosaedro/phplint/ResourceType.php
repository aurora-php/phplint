<?php

/*. require_module 'standard'; .*/

namespace it\icosaedro\phplint;

#require_once __DIR__ . "/../../../autoload.php";
require_once __DIR__ . "/TypeInterface.php";


/**
	Singleton object that represents the resource type.
	The Types::parseType() method uses this class to represent the result
	of the compilation of a textual type descriptor.
	@author Umberto Salsi <salsi@icosaedro.it>
	@version $Date: 2012/01/22 19:28:14 $
*/
class ResourceType implements TypeInterface {

	private static /*. self .*/ $singleton;

	private /*. void .*/ function __construct(){}

	/**
		Return the instance that represents the resource type.
		@return self
	*/
	static function factory()
	{
		if( self::$singleton === NULL )
			self::$singleton = new ResourceType();
		return self::$singleton;
	}


	/**
		Checks if the expression or variable passed is of type resource.
		@param mixed $v Any expression or variable.
		@return bool True if the expression is either the NULL value or a value
		of the type resource.
	*/
	function check($v)
	{
		return is_null($v) or is_resource($v);
	}


	/**
		Returns the descriptor of this type, that is "resource".
		@return string The string "resource".
	*/
	function __toString()
	{
		return "resource";
	}

}
