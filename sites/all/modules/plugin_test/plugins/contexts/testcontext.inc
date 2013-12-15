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
  $context = new ctools_context('testcontext');
  $context->plugin = 'testcontext';

  if ($empty) {
  	return $context;
  }

  $context->data = new stdClass();
  // Populate our keyword with data.
  $context->data->keyword1 = t('Data for keyword 1');
  $context->data->keyword2 = t('Data for keyword 2');
  
  if ($conf) {
  	// Data coming from settings form.
  	if (!empty($data)) {

  	}
  }
  else { 
  	//Data coming from url argument - it's a string.
  	$context->argument = $data;
  	$context->argument_length = strlen($context->argument);
  }
  return $context;
} 

/**
 * Callback function.
 * 
 * Provide a list of keywords for use in a content type, pane etc.
 */
function testcontext_convert_list() {
	return array(
		'keyword1' => t('Keyword 1'),
		'keyword2' => t('Keyword 2'),
	);
}

/**
 * Callback function.
 *
 * Convert a keyword into the associated data from the conbtext.
 */
function testcontext_convert($context, $type) {
	switch ($type) {
		case 'keyword1':
			return $context->data->keyword1;
		case 'keyword2':
			return $context->data->keyword2;
	}
}