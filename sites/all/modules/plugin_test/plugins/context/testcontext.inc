<?php

/**
 * @file
 *
 * Defines a test context plugin for Plugin test module.
 *
 * This plugin is a context type plugin.
 */

$plugin = array(
	'title' => t('Test context'),
	'description' => t('A simple test context'),
	'context' => 'plugin_test_context_create_testcontext',
	'context name' => 'testcontext',
	'keyword' => 'testcontext',
	// Provide a list of keywords that expose content from the context.
	'convert list' => 'testcontext_convert_list',
	// Convert keywords into data.
	'convert' => 'testcontext_convert',
	'placeholder form' => array(
		'#type' => 'textfield',
		'#description' => t('Enter some data for the test context.'),
	),
);

/**
 * Callback function to create the test context
 *
 * @param $empty
 *   If true, return an empty context
 * @param $data
 *   If from settings form, an array of data. If from argument, a string.
 * @param $conf
 *   TRUE if data is coming from admin form, FALSE if it's from URL.
 */
function plugin_test_context_create_testcontext($empty, $data = NULL, $conf = FALSE) {
  $context = ctools_context('testcontext');
  $context->plugin = 'testcontext';

  if ($empty) {
  	return $context;
  }

  
} 