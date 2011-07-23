<?php

class imce_boxes extends boxes_box {
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    return array(
      'link_url' => '<front>',
      'imce_image_path' => '',
    );
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form() {
    if (filter_access($this->options['format'])) {
      $form['link_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Link URL'),
        '#default_value' => $this->options['link_url'],
      );
      $form['imce_image_path'] = array(
        '#type' => 'textfield',
        '#title' => t('Image path'),
        '#default_value' => $this->options['imce_image_path'],				
        '#suffix' => '<div id="imce-browser-ph"><a href="#">' . t('Browse') . '</a></div>',
      );
//      $imagecahece_presets_options = array(
//        'inner_left_box' => t('Inner left'),
//      );
      return $form;
    }
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    $title = isset($this->title) ? check_plain($this->title) : NULL;
    $block['title'] = $title;
    $block['subject'] = NULL;
    $block['delta'] = $this->delta;
    $link_options = array(
      'html' => TRUE,
    );
    
    $image_path = substr($this->options['imce_image_path'], strlen(base_path()));//$this->options['imce_image_path'];
    $image = '<img src="' . base_path() . $image_path . '" alt="' . $title . '" title="' . $title . '" />';
    $block['content'] .= l($image, $this->options['link_url'], $link_options);
    return $block;
  }
}