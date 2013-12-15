<?php

/**
 * @file
 *
 * Defines a test content type ctools plugin.
 */

$plugin = array(
	'title' => t('Test context content type'),
	'description' => t('A test content type. Works with test context plugin.'),
	'content types' => array('testcontext_content_type'),
	'render callback' => 'testcontext_content_type_render',
	'single' => TRUE,
	'required context' => new ctools_context_required(t('Test context'), 'testcontext'),
	'category' => array(t('Plugin test'), -5),
);

function testcontext_content_type_render($subtype, $cont, $args, $context) {

}