<?php

/**
 * @file
 *
 * Defines a test content type ctools plugin.
 */

$plugin = array(
	'title' => t('Test context content type'),
	'description' => t('A test content type. Works with test context plugin.'),
	'content_types' => array('testcontext_content_type'),
	'render callback' => 'testcontext_content_type_render',
	'single' => TRUE,
	'required context' => new ctools_context_required(t('Test context'), 'testcontext'),
	'category' => array(t('Plugin test'), -5),
);

function testcontext_content_type_render($subtype, $conf, $args, $context) {
	$block = new stdClass();

	$block->title = t('Test context content type');
	$block->content = array();
	$block->content['context_keyword1'] = array(
		'#markup' => '<p>Data for keyword1: ' . $context->data->keyword1 . '</p><br>',
	);  
	$block->content['context_keyword2'] = array(
		'#markup' => '<p>Data for keyword2: ' . $context->data->keyword2 . '</p><br>',
 	);
 	$block->content['context_arglength'] = array(
 		'#markup' => '<p>Arg length: ' . $context->argument_length . '</p><br>',
 	);
	$block->content['context_argument'] = array(
 		'#markup' => '<p>Argument: ' . $context->argument . '</p><br>',
 	);


	return $block;
}