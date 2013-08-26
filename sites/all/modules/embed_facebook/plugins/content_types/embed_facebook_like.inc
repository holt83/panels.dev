<?php

/**
 * @file
 * 
 * This file describes the plugins that the embed facebook module provides. The
 * type of the plugins is a simple content type plugin with no context. 
 */

$plugin = array(
  'title' => t('Embed facebook plugin'),
  'description' => t('Embed various facebook plugins'),
  'single' => TRUE, // No subtypes
  'content_types' => array('embed_facebook_like'), // Constructor
  'render callback' => 'embed_facebook_like_render',
  'defaults' => array(), // Default context (nothing)
  'edit form' => 'embed_facebook_like_edit_form',
  'category' => array(t('Embed Facebook'), 0),  
);

function embed_facebook_like_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = t('Embed Facebook');
  $block->content = array(
    '#theme' => 'embed_facebook__like',  
    '#type' => 'like',
    '#action' => 'recommend',  
  );
  return $block;
}

function embed_facebook_like_edit_form($form, &$form_state) {
  return $form;
}

function embed_facebook_like_edit_form_submit($form, &$form_state) {
  
}
