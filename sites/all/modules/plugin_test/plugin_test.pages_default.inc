<?php

function plugin_test_default_page_manager_pages() {

	// Start export	
	$page = new stdClass();
	$page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
	$page->api_version = 1;
	$page->name = 'plugin_test_page';
	$page->task = 'page';
	$page->admin_title = 'Plugin test page';
	$page->admin_description = 'Test page for the Plugin test module.';
	$page->path = 'plugin_test/%tc';
	$page->access = array();
	$page->menu = array();
	$page->arguments = array(
	  'tc' => array(
	    'id' => 1,
	    'identifier' => 'Test context argument',
	    'name' => 'testcontext_arg',
	    'settings' => array(),
	  ),
	);
	$page->conf = array(
	  'admin_paths' => FALSE,
	);
	$page->default_handlers = array();
	$handler = new stdClass();
	$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
	$handler->api_version = 1;
	$handler->name = 'page_plugin_test_page_panel_context';
	$handler->task = 'page';
	$handler->subtask = 'plugin_test_page';
	$handler->handler = 'panel_context';
	$handler->weight = 0;
	$handler->conf = array(
	  'title' => 'Panel',
	  'no_blocks' => 0,
	  'pipeline' => 'standard',
	  'body_classes_to_remove' => '',
	  'body_classes_to_add' => '',
	  'css_id' => '',
	  'css' => '',
	  'contexts' => array(
	    0 => array(
	      'identifier' => 'Test context',
	      'keyword' => 'testcontext',
	      'name' => 'testcontext',
	      'id' => 1,
	    ),
	  ),
	  'relationships' => array(),
	  'access' => array(
	    'logic' => 'and',
	  ),
	);
	$display = new panels_display();
	$display->layout = 'threecol_33_34_33';
	$display->layout_settings = array();
	$display->panel_settings = array(
	  'style_settings' => array(
	    'default' => NULL,
	    'left' => NULL,
	    'middle' => NULL,
	    'right' => NULL,
	  ),
	);
	$display->cache = array();
	$display->title = '';
	$display->content = array();
	$display->panels = array();
	  $pane = new stdClass();
	  $pane->pid = 'new-1';
	  $pane->panel = 'left';
	  $pane->type = 'testcontext_content_type';
	  $pane->subtype = 'testcontext_content_type';
	  $pane->shown = TRUE;
	  $pane->access = array();
	  $pane->configuration = array();
	  $pane->cache = array();
	  $pane->style = array(
	    'settings' => NULL,
	  );
	  $pane->css = array();
	  $pane->extras = array();
	  $pane->position = 0;
	  $pane->locks = array();
	  $display->content['new-1'] = $pane;
	  $display->panels['left'][0] = 'new-1';
	  $pane = new stdClass();
	  $pane->pid = 'new-2';
	  $pane->panel = 'middle';
	  $pane->type = 'custom';
	  $pane->subtype = 'custom';
	  $pane->shown = TRUE;
	  $pane->access = array();
	  $pane->configuration = array(
	    'admin_title' => 'Test testcontext keywords',
	    'title' => 'Test testcontext keywords',
	    'body' => 'Here we test the testcontext kyewords. Lets go...

	Testcontext from argument plugin:
	%tc:keyword1
	%tc:keyword2

	Testcontext added from admin:
	%testcontext:keyword1
	%testcontext:keyword2
	',
	    'format' => 'filtered_html',
	    'substitute' => 1,
	  );
	  $pane->cache = array();
	  $pane->style = array(
	    'settings' => NULL,
	  );
	  $pane->css = array();
	  $pane->extras = array();
	  $pane->position = 0;
	  $pane->locks = array();
	  $display->content['new-2'] = $pane;
	  $display->panels['middle'][0] = 'new-2';
	$display->hide_title = PANELS_TITLE_PANE;
	$display->title_pane = '0';
	$handler->conf['display'] = $display;
	$page->default_handlers[$handler->name] = $handler;
	//End export

	$pages = array();
	$pages['plugin_test_page'] = $page;

	return $pages;
}