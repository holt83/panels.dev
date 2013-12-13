<?php

/**
 * @file
 *
 * Defines a test argument plugin for the Plugin test module.
 *
 * This plugin is an argument hanlder for panels pages. It sets up a context
 * of type testcontext defined by testcontext plugin.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
	'title' => t('Test context argument'),
	'keyword' => 'testcontext',
	'description' => t('Creates a test context from an argument'),
	'context' => 'testcontext_arg_context',
	'placeholder form' => array(
		'#type' => 'textfield',
		'#description' => t('Enter the test context argument'),
	),
);

/**
 * Callback function to setup the testcontext from the argument. This callback
 * isd defined in the plugin array above.
 */
function testcontext_arg_context($arg = NULL, $conf = NULL, $empty = FALSE) {
	// If empty is true caller wants generic, unfilled context.
	if ($empty) {
		return ctools_context_create_empty('testcontext');
	}
	if (empty($arg)) {
		return FALSE;
	}
	return ctools_context_create('testcontext', $arg);
}